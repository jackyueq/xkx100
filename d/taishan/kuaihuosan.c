// Room: /d/taishan/kuaihuosan.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��������������ű����������ɽ����ɽ���ˣ�����̹;����ɽ��
Χ�����پ�������ˬ���ġ��ϲ�����Ȫ���������⡰��ҺȪ����ˮ����
����
LONG );
	set("exits", ([
		"north" : __DIR__"yunbu",
		"south" : __DIR__"ertian",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 670);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
