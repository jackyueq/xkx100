// baishulin1.c ������
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�ƹ������ȵ�ɽ�ڣ���ǰ��һƬ������֣���������ɽ�ڵ�ס��
���ߣ���ɽ�µ�ɽ·�ϸ����벻������İ�����������ô����ô�ߡ�
��̤���������У�����ȫ��ͷ������Ҷ��ס�ˣ�Խ�������������
Խ���İ���
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"cuipinggu",
                "northup" : __DIR__"baishulin3",
                "east" : __DIR__"baishulin2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 30);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}