// minju2.c ���
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����é�ݴ�ķ��ݣ���ͽ�ıڣ��ݽǵ��׸��ǿյģ�������
��ˮ��Ҳ�ǿյġ�����ȱ�첲���ȵ����ο�ǽ���š����������Ѿ�����
����ֵǮ�Ķ���ȫ�������ˡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"xijie",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3160);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}