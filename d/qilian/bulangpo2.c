// Room: /d/qilian/bulangpo2.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ɽ��Խ��Խ���գ����������Ӳݣ���ɽ��Ҳ�����ж���Ψ��ɽҰ��
�ͼ�ֻ��ӥ����춿ա���������ʮ�����ң��һ�룬�������������
���۴��̣�����ͨ�롣
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northwest" : __DIR__"datongling",
		"southdown" : __DIR__"bulangpo1",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu": 2,
	]));
	set("coor/x", -9900);
	set("coor/y", 2900);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}