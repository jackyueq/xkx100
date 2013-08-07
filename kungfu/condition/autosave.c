// autosave.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	object obj, *guards;

	switch (duration)
	{
		case 1:
			message("channel:snow",HIG"�����̡����ĵ������Զ����̡�\n"NOR,me);
			me->save();
			break;
		case 4:
			if (me->query("food") <= 20 && !(wizardp(me) && me->query("env/invisibility")))
				message_vision( HIY"ͻȻ$N����һ�󡰹��������죬æ��˫����������ӣ����ö�Ŷ��Ҫ���ҵ�Ե�ȥ����\n"NOR, me);
			break;
		case 7:
			if (me->query("water") <= 20 && !(wizardp(me) && me->query("env/invisibility")))
				message_vision( HIY"$N������ͷ��������ѵ��촽������Ҫ�ȵ�ʲô�ˡ�\n"NOR, me);
			break;
		default:
			if (duration == 13) duration = 0;	
			break;
	}
	if( me->query_temp("guardfor") ) obj = me->query_temp("guardfor");
	if( me->query_temp("guardto") ) obj = environment(me);
	if( me->query_temp("guardfor") || me->query_temp("guardto") )
	{
		me->add("qi", -me->query("max_qi")/10);
		me->add("jing", -me->query("max_jing")/10);
		if(me->query("qi")<200 || me->query("jing")<200)
		{
			if (me->query_temp("guardfor"))
			{
				message_vision( HIY"$N�ػ���ô�ã�ʵ����̫���ˣ�ֻ�÷������ػ�"+obj->name()+"���뷨��\n"NOR, me);
				guards = obj->query_temp("guarded");
				guards -= ({ me });
				obj->set_temp("guarded", guards);
				me->delete_temp("guardfor");
			}
			else
			{
				message_vision( HIY"$N������ô�ã�ʵ����̫���ˣ�ֻ�÷����˰���"+obj->query("short")+"���뷨��\n"NOR, me);
				obj->delete("guarded/"+me->query_temp("guardto"));
				me->delete_temp("guardto");
			}
		}
		else
		{
			if(me->query("qi")<500 || me->query("jing")<300)
				message_vision("$N������ô�ã����ú��ۡ�\n",me);
			else message_vision("$N����һ�ᣬ���е����ˡ�\n", me);
		}
	}
  if (me->query("max_nuqi")>0 && me->query("nuqi")>0 && 
        me->query("nuqi") < me->query("max_nuqi"))
   me->add("nuqi",-5);
   if (me->query("nuqi") < 0) me->set("nuqi",0);
	me->apply_condition("autosave", duration + 1);
	return CND_CONTINUE;
}
