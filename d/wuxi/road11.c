// Room: /d/wuxi/road11.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "��ͷ�");
	set("long", @LONG
̫��������ǧ�꣬���޷������ͷ����������㲻�ɵؾ�̾��
�侹����˷羰����֮����ֻ����ɽ��ʯ��ͻ��̫���̲�֮�У����
��ʯ (shi)�����Ժ��棬�����İ�������ϸ�ڡ��Ƿ�Զ����ֻ������
ˮ��������Ž���Ŀ�����ľ���Ȼ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("item_desc", ([
		"shi" : "�ĸ��Ծ������Ĵ��֣�  "HIG"������Խ\n"NOR,
	]));
	set("exits", ([
		"east"   : __DIR__"road12",
		"north"  : __DIR__"road10",
	]));
	set("coor/x", 370);
	set("coor/y", -880);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}