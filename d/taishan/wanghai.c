// Room: /d/taishan/wanghai.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
��������������ʯ����ʯ̹��������ԣ�ʯ�����һСˮ�ۣ�ÿ��
���ˮ˳�۶��� ������֮���������ֹŶ���̡�˫����ע����Ԭ��
�����顰��������
LONG );
	set("exits", ([
		"north"    : __DIR__"xianren",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 740);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
