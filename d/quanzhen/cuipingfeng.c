// cuipingfeng.c �����嶥
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�����嶥");
        set("long", @LONG
�����Ǵ�����ķ嶥��������������ɽ�ĵ�һ�壬Ҳ�����һ
��ɽ�塣���±߽���һ��Сͤ�ӣ����߽�ͤ��ƾ��Զ����Զ����ɽ��
����Ư�����ƣ�����������ʲô������ɽ����������ϧ�����ƾ���ס
�ˡ������ο�Ҳ��ͤ��Ъ�ţ������������Ŵ˵�������
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"baishulin3",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));

	set("coor/x", -3140);
	set("coor/y", 50);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}