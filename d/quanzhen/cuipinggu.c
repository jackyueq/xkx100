// cuipinggu.c ������
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǰ��һ����������Ĵ�ɽ�ڣ�ɽ���������дж�������һ
�ۿ���ȥ��ȫ��һƬ����ɫ������Ǵ˵����д����ȵ�������������
�������ϣ��͵�������ɽ�ϵİ������ˡ�
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "northup" : __DIR__"baishulin1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 20);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}