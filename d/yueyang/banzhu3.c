// Room: /d/yueyang/banzhu1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ�����֡����紵����һ��Ҷ�졣�����ֽ��������ھ�
ɽ�����೤�ڰ���ɽ�ϡ����ʩ�����ڡ�������ӽ����д�С�������
�Ĺ۸У� ������ɭɭ��ˮ�壬������������ɽ��������������ᣬ��
�ǵ������ߡ���
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"erfeimu",
		"west"  : __DIR__"banzhu3",
		"south" : __DIR__"banzhu1",
		"north" : __DIR__"banzhu2",
	]));
	set("coor/x", -1680);
	set("coor/y", 2300);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
