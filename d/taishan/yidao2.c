// Room: /d/taishan/yidao2.c
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
		"southwest" : __DIR__"yidao1",
		"north"     : __DIR__"yidao3",
	]));
	set("objects",([
		__DIR__"npc/shu-sheng" : 1,
		CLASS_D("taishan")+"/tianyi" : 1,
	]));
 	set("outdoors", "jiangnan");
	set("coor/x", 400);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
