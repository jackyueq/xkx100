// Room: /d/qilian/tieshishan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	object ob;
	set("short", "��ʯɽ");
	set("long", @LONG
����������ɽ������ʮ�ﴦ��ɽ����ף�ͨɽһɫ��ڣ���ͺͺ��
û��һ����������ɽ�����ʯ����ɫ��ī�����ճ�������������������
���������ߣ��ͽ��뱱����ɽ���ˡ�
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"east"      : __DIR__"qilianshan",
		"west"      : __DIR__"zibaipo",
		"northwest" : __DIR__"ailaoshan",
	]));
	set("objects", ([
//		__DIR__"obj/ironstone" : random(2),
	]));
	set("coor/x", -13000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
//	replace_program(ROOM);
  ob = new(__DIR__"obj/ironstone");
	if (ob->violate_unique())
	destruct(ob);
	else
	ob->move(this_object());
}