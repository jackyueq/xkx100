// Room: /heizhao/shanding.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ɽ�嶥���ǿ�ƽ�أ����ѳɶ�ʮ��Ķɽ����ź̵���һ����
ͷ������ߣ�һ����������ಲ���������ۼ�ϥ�����ڰڲ�ɽ����
һͷ��������һ����ʯ�ϣ�����������վ�����������װ����Ĵ��
ţ��
LONG );
	set("outdoors", "taoyuan");
	set("objects", ([
		CLASS_D("dali")+"/yideng/gen" : 1,
		"/d/wudang/npc/cow" : 1,
	]));
	set("exits", ([
		"down"     : __DIR__"shanlu10",
		"northup"  : __DIR__"shiliang1",
	]));
	set("coor/x", -5020);
	set("coor/y", -1260);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}