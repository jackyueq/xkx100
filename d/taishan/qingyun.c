// Room: /d/taishan/qingyun.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "���ƶ�");
	set("long", @LONG
���������ƶ����������춴�������̣�����ƶ�֮�������������
�¡��׳ơ����﹫�򴫡����ء���ʯ������������ϣ����糯�������
�����ߣ�Ψ̩ɽ��������ָ�˵ء� 
LONG );
	set("exits", ([
		"westup" : __DIR__"xiangshan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 760);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
