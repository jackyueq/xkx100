// Room: /d/yueyang/banzhu1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ�����֡����紵����һ��Ҷ�졣�����ֽ�����������
���������Ա𴦣��ڶ���߼��ͻ���ʧ����Ӱ���٣�����ٽ���������
�ƻؾ�ɽ����һ�����ǰߺ����۵��ˡ��ƴ�������д�С����������ƣ�
���ݵ���Ѳ��������������Թˮ�Ƽ䡣��ʱ����֪���٣�ֱ���������
�ߡ���
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"banzhu2",
		"west"      : __DIR__"erfeimu",
		"south"     : __DIR__"banzhu1",
		"north"     : __DIR__"banzhu3",
	]));
	set("coor/x", -1660);
	set("coor/y", 2300);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
