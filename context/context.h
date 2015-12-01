// Copyright 2015 Alexander Palaistras. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

typedef struct _engine_context {
	#ifdef ZTS
	void *ptsrm_ls; // Pointer to TSRM local storage.
	#endif

	void *parent; // Pointer to parent Go context, used for passing to callbacks.
	int (*write)(struct _engine_context *context, const char *msg, unsigned int len);
	void (*header)(struct _engine_context *context, unsigned int operation, const char *header, unsigned int len);
} engine_context;

engine_context *context_new(void *parent);
void context_exec(engine_context *context, char *filename);
void *context_eval(engine_context *context, char *script);
void context_bind(engine_context *context, char *name, void *value);
int context_write(engine_context *context, const char *str, unsigned int len);
void context_header(engine_context *context, unsigned int operation, const char *header, unsigned int len);
void context_destroy(engine_context *context);

#endif