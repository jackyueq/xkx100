// Room: /d/taishan/yidao.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ������
����������߷ɳ۶���������һ·��������·�������������������
�֡�
LONG );
	set("exits", ([
		"west" : "/d/city/dongmen",
		"east" : __DIR__"yidao1",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 3,
	]));
 	set("outdoors", "jiangnan");
	set("coor/x", 200);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
