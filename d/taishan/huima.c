// Room: /d/taishan/huima.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ʯ�أ�������ء������ҡ��˵�ɽ�ƶ��ͣ����·ת��
�����˲��ܵǣ���������˵������������̩ɽ�����������������
���ʣ������˰���Ҫ�ĳ�С����ɽ��ʯ������·�᧶����������϶�
�����ۣ��������㣬�ʳ������̡��±��⡰����ؿ�����ơ���
LONG );
	set("exits", ([
		"northup"  : __DIR__"ertian",
		"eastdown" : __DIR__"hutiange",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/jian-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 390);
	set("coor/y", 650);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
