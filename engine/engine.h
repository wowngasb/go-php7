// Copyright 2015 Alexander Palaistras. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.

#ifndef __ENGINE_H__
#define __ENGINE_H__

typedef struct _php_engine {
	#ifdef ZTS
	void ***tsrm_ls; // Local storage for thread-safe operations, used across the PHP engine.
	#endif
} php_engine;

php_engine *engine_init(void);
void engine_shutdown(php_engine *engine);

#endif