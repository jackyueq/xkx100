// Room: /d/qilian/bonanshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
�����ߣ������ѽ����ز���ƽ̹�����������ת��ɽ������·����
���ж��ˣ�ֻʣ������ƽ��ɽ·����������������ɽ��������ͨ������
�ٵ���
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : "/d/xingxiu/xxroad2",
		"north"    : __DIR__"bulangpo1",
	]));
	set("coor/x", -9900);
	set("coor/y", 2700);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}