// Room: /d/taishan/xitian.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�¹۷�ɽ���������ʯ�������ţ��������ն�����Ƶģ�����᷶�
��������ڣ��������š�����������ֹŶ���ʯ�����⡰���ڡ�������
�ڡ���̩ɽ�ǡ����̵������֮Ϊ������������������ʯ�����ɣ�����
��Ҳ����
LONG );
	set("exits", ([
		"southdown" : __DIR__"yueguan",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/yuqingzi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 780);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
