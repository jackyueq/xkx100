// Room: /d/xiangyang/daxiaochang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��У��");
	set("long", @LONG
���������ؾ�����У�ľ�ʿ�ĵط���ֻ��У������ΡΡ��
��һ����̨��̨��������ǧ�������Ӱ�ʡ�̨ǰ����������ˣ�
��˶�������˶����춷��У����ۼ������ٸ��Ĵ����ϵ�ؤ
����ӡ����Ƕ�������ѡ����ؤ������ġ�
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"westjie3",
	]));
	set("coor/x", -540);
	set("coor/y", -510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
