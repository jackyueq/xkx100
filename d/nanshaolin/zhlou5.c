// Room: /d/nanshaolin/zhlou5.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥���");
	set("long", @LONG
һ����ȥ��ֻ��������ƣ���ɽ���У����˽�����֮������Ϊһһ
ɨ������ǰ�����������¥�������������¾����۵ס�������������
���������������������Կ���һ��Ƭ�����֡�
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou6",
		"down" : __DIR__"zhlou4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}



