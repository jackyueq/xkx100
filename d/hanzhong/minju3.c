// minju3.c ���
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ�������ӣ����ζ��ܾ��ˣ����ҿ��ó������Լ����ô��
��ƴ�������ģ��������õúܸɾ���ǽ����б����һ֧�Բ棬Ҳ�����
�����˻��Ǹ����Ը��֡�
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"guchang",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3180);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}