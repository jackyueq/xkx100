#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","����������֮��");
	set("long",@LONG
�ⶴ��ʵ��ǳ���в������ɣ��ѵ־�ͷ�����г���һ��ʯ����һ
��ʯ����ͱ��������ˡ�������һ����ʯ���𣬼���һ����Ĺ���ұ�
�Ͽ��������ֵ���
    ���ݺὭ����ʮ���أ�ɱ����ܣ��ܾ�Ӣ�ۣ����¸��޿��֣���
���κΣ�Ω������ȣ��Ե�Ϊ�ѡ��غ�����ƽ��һ���ֶ����ɵã���
�����ѿ�Ҳ��
                                         ��ħ������ܡ���
LONG
	);
	set("exits",([
		"south":__DIR__"shandong1",
	]));
	set("coor/x", -400);
	set("coor/y", -430);
	set("coor/z", 0);
	setup();
}
void init()
{
	object me=this_player();
	me->set_temp("dugu_visit",1);
}	