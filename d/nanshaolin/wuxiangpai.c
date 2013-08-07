// Room: /d/nanshaolin/wuxiangpai.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"������"NOR);
	set("long", @LONG
ͨ�������ƽ���������ʦ��ǰ��������ң�������Ϊ�Ұ����ܲ�͸
�⡣�����а���һ����ͭ�ף�����ʢ����ˮ���������ԡ�Ϊ�������һ
�������˵�����ʦ�����ܴ������ظ���֮����Ѱ�ž������������
���£��������ڴ�����(strike)�����Ʒ������Ƿ��켫֮�ز�����һ��
��ѧ�ذ¾����ڴ˶���֮�С�
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_strike","strike");
}
int do_strike(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("strike", 1), exp = me->query("combat_exp");

	if (arg!="shui") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"��׼ͭ���е�ˮ�淢�ƻ�����\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"�㹦��̫ǳ��ͭ������ˮ��Ҳû����һ�㡣\n"NOR);
 		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"�㾭��̫ǳ��ͭ������ˮ��Ҳû����һ�㡣\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"���������ۣ�ͭ���ھ�ˮΪ�������������ѻ�Ӧ֮����\n"NOR);
		return 1;
	}
        if (lvl >= 30 && lvl <= 100&&arg=="shui" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();     
			return 0;
		}
                me->receive_damage("jing", 30);
                me->improve_skill("strike", (me->query("int"))*3/2);
                write(HIB"�����ˮ��ңң���ƣ����ڼ���ƬƬˮ����������������о�����\n"NOR);
		return 1;
	}
}

