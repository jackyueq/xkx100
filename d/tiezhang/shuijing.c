// Room: /d/tiezhang/shuijing.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIM"����Ȫ"NOR);
	set("long", @LONG
����ǰ�У�һ·���̺���ϣ���ɽ��Ұ�����ʻ������������Ѽ���
ת��һ�����ԣ���ǰ����һ��Ȫˮ��Ȫˮ�峺���ף�ɢ����һ��������
Ƣ��������Ȫˮ���Աߣ�����һȺȺ�ĺ������򻨻�ף���ڻ��ϣ���
�����衣��������η�ˣ��ɽ�ʱ�������ǵ�����ͣ����
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"guajia",
	]));
	set("no_clean_up", 0);
	set("resource/water", 1);

	set("coor/x", -2020);
	set("coor/y", -1980);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}