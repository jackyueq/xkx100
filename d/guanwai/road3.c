// /guanwai/road3.c
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
		"north"     : __DIR__"ningyuan",
		"southwest" : __DIR__"road2",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 6020);
	set("coor/y", 5120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}