// Room: /d/nanshaolin/twdian.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"������"NOR);
	set("long", @LONG
�����������µ��е�����������������ƣ�᣽Ƕ��ˡ�����ǰ
��Ҫ��ʢ�Ķࡣ��ǰ�����Ÿ�����ӣ��ƺ���Զ��Ц��������շ���
�������������ԣ���ִ�������˳�������������ϰ������ļ����ߣ���
�յ����վ������Τ�ԡ�ֻ���������ף�����Ӣ�����������ݣ�˫��
��ʮ������ƺ�����ϡ�
LONG );

	set("exits", ([
		"south" : __DIR__"qdian",
		"north" : __DIR__"sblu-1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangxian" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("coor/x", 1820);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

