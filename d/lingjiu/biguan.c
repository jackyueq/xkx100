// ROOM : biguan.c
inherit ROOM;
void create()
{
	set("short","�չ���");
	set("long",@LONG
������ɽͯ�ѱչ������ĵط���ֻ��һ����Ľ�С, ò�紦�ӵ�ʮ
�˾����Ů����ϥ�������������������µ���ɽͯ�ѡ��������������
�����ӣ�ǧ��Ҫ���״����
LONG );
	set("sleep_room", 1);
	set("exits",([
		"south" : __DIR__"men3",
	]));
	set("objects",([
		CLASS_D("lingjiu")+"/tonglao" : 1,
	]));
	set("coor/x", -51000);
	set("coor/y", 30190);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}