// /guanwai/road2.c
inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������ͨ������Ĺٵ������׿�Ĵ����ȫ���ɻ����̳ɣ��ɲ���
��������������ӵ���������ǽ����ؿڵıؾ�֮·��·��������Ⱥ��
���˶�����������Ƥ����ҩ�ĵ������ˡ�ż�������Źٱ�����ɳ۶�����
LONG );
	set("exits", ([
		"northeast" : __DIR__"road3",
		"southwest" : __DIR__"road1",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 6010);
	set("coor/y", 5110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}