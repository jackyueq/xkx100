// Last Modified by winder on Apr. 25 2001
#include <ansi.h>

int accept_hit(object who)
{
	object me = this_object();
	if (me->query("ygjg")==who) return 1;
	else 	if (me->query("ygjg"))
	  return notify_fail(CYN"��Ը�"HIR"�ɹű�"CYN"����ȥ�ҹ������������ᰲ�������سǵģ�\n"NOR);
	return 1;
}
int accept_fight(object who)	{return accept_hit(who);}
int accept_kill(object who)		{return accept_hit(who);}
int accept_ansuan(object who) {return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}