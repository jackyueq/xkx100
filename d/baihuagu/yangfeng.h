// yangfeng.h
#include <ansi.h>
int do_yang(string arg)
{
	object bee;
	object me,obj;
	int c,qufeng;

	me=this_player();
	seteuid(getuid());
	if(!arg)
		return notify_fail("������ʲô��\n");
	if(arg != "yu bee" || arg != "yu bee")
		return notify_fail("��ֻ������䡣\n");
	if(me->is_busy()||me->query_temp("marks/bee1"))
		return notify_fail("����æ���ء�\n");
	if ( present("mi", me) )
		return notify_fail("�������ŷ����أ������Ƚ�������ͯ�ɡ�\n");
//	bee=new("/d/baihuagu/npc/yubee");
//	bee->move(environment(this_player()));
//	me->set_leader(bee);
//	bee->set_leader(me);
	message_vision( HIY"$N��һ�����䣬������ķɳ�һȺ��䡣$NɵЦһ������ʼ���۷���ˣ��\n"NOR, me, obj);
	qufeng = me->query_skill("qufeng",1);
	c=20;
	if (wizardp(me)) c=3;
	else if (qufeng > 50 ) c = c * 50  / qufeng; // 200������ 1/4
	me->apply_condition("yubee", c);
	me->set_temp("marks/bee1",1);
	return 1;
}
int do_quit(string arg)
{
	write(this_player()->query("name")+"�����ڸ�ɶ����ѽ��ר������ɣ�\n");
	return 1;
}

