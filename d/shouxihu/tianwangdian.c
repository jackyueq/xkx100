// Room: /yangzhou/tianwangdian.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
ɽ����Ϊ������������У��������������裬�������շ���
ǰ�����(lian)����������Τ�ӡ������в����Ĵ�������������������
���������Ϸ�����������������������Ŀ��������������������
LONG );
	set("item_desc", ([
		"lian" : "
        ����������������֮��

        ���ճ�ЦЦ�����Ц֮��
\n"
	]));
	set("objects", ([
		"/d/hangzhou/npc/shami" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"yongdao",
		"south" : __DIR__"shanmen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}