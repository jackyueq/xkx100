// yuzhengong.c ���湬
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���湬");
        set("long", @LONG
��������������ǰ�ľ�ַ���������������˲�����֮ǰ���޵�
�ط��������ִ�ȫ��̺󣬴˵صĲ���ʵ��̫С���ͽ�������Ǩ����
��ɽ�ϣ����˵����¸���Ϊ���湬���Լ���õ�֮�⡣����ܾ�û��
�������ˣ������϶������˻ҳ���
LONG
        );
        set("exits", ([
                "south" : __DIR__"fangzhenqiao",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 150);
	set("coor/z", 190);
	setup();
        replace_program(ROOM);
}