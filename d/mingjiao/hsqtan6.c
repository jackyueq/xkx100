//HSQTAN6.C

inherit ROOM;

void create()
{
	set("short", "��̶");
	set("long", @LONG
�����ˮֻ���������վ��ˮ�У��Ըо�����ӽ������𣬾���
��ɢ��
LONG );
	set("exits", ([
		"up"   : __DIR__"hsqmen",
		"west" : __DIR__"hsqtan5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 940);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}