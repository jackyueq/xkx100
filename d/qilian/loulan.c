// Room: /d/qilian/loulan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "¥������");
	set("long", @LONG
����¥������������أ��޵�����¥���ǡ�����¥����ֹͣ�򺺳�
���������ǲ��ȥ��ƽ֮����ʱ�������࣬����¥��֮������ͳ���
һ�����ǡ���������꣬¥���Ǿ���ʧ�ˡ��ݴ�����ɳ�£���֪�Ƿ���
ʵ��
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northeast" : __DIR__"jiuquan",
		"west"      : "/d/xingxiu/yueerquan",
	]));
	set("objects", ([
		"/d/xingxiu/npc/shachong" : 2,
	]));
	set("coor/x", -20300);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}