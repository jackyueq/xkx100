// Room: /d/taishan/hongmen.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
����Ժ���������ʿ֮���Ƹ�����Ź���������Ժ����ԭ��ľ����
�շ𣻶��д���ʽ����ͤ����ʱ�����ٻµ�ɽ���˸��£����д���ʽ��
ͥ��
LONG );
	set("exits", ([
		"west"      : __DIR__"hongmen",
		"southeast" : __DIR__"bailuo",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 410);
	set("coor/y", 550);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
