#ifndef ANIMMAPPER_H
#define ANIMMAPPER_H

#include <list>
#include <map>
#include <vector>
#include "animmanager.h"
#include "colobjectgroup.h"
#include "airloader.h"


class AnimMap;
class ActionDef;
class FrameDef;
class AIRLoader;
typedef boost::shared_ptr<AIRLoader> AIRLoaderPtr;

#define USE_ANIMGR  1

class AnimMap
{
    public:
		AnimMap();
		~AnimMap();
		/**
		 * Carrega um arquivo de anima��es.
		 * @arg filename Nome do arquivo
		 */
		void open(const char *filename);
		/**
		 * Escolhe a anima��o para exibir
		 * @arg no  N�mero do action
		 */
		void set(int no);
		/**
		 * Atualiza os contadores da anima��o com 1 tick de tempo.
		 */
		void update();
		/**
		 * Retorna o n�mero do action.
		 */
		int number();
		/**
		 * Retorna o n�mero do grupo do sprite atual da anima��o.
		 */
		int group();
		/**
		 * Retorna o n�mero do indice do sprite atual da anima��o.
		 */
		int index();
		/**
		 * Retorna o valor de x do sprite atual da anima��o.
		 */
		int x();
		/**
		 * Retorna o valor de y do sprite atual da anima��o.
		 */
		int y();
		/**
		 * Retorna se o sprite atual � invertido horizontalmente.
		 */
		bool fliph();
		/**
		 * Retorna se o sprite atual � invertido verticalmente.
		 */
		bool flipv();
		ColObjectGroup *clsn1();
		ColObjectGroup *clsn2();
		ColObjectGroup *clsn1default();
		ColObjectGroup *clsn2default();

    private:
		FrameDef *frame;
		ActionDef *action;
#if USE_ANIMGR
		AIRLoaderPtr loader;
#else
		AIRLoader *loader;
#endif

		// player
		int time;
		int elemTime;
		int elem;
};


#endif // ANIMMAP_H
