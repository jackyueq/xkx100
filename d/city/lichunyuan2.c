// Room: /city/lichunyuan2.c
// Dec.12 1997 by Venus
inherit ROOM;
void create()
{
        set("short", "����¥");
        set("long", @LONG
��վ������Ժ��¥���������������첻�����ơ����õľ��Ծ��µ�
���ϵ��£�ͻȻ�������Ī�����ջ�ͳ嶯��
    �������������ǧ�������ڵ��ֶ����㣬���뵽���ǿ��ܾ�������
�����е��۸��ڶ�����ʱ��Ϊ���ġ�
LONG);
        set("exits", ([
            "down" : __DIR__"lichunyuan",
        ]));
        set("objects", ([
            __DIR__"npc/guigong" : 1,
//            __DIR__"usa/albright" : 1,
        ]));
	set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        set("piao_room", "1");
	set("coor/x", 30);
	set("coor/y", 20);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
    if (me->query_condition("prostitute"))
      return notify_fail("�깫һ�ѱ�ס�㣺�����������ӣ�\n");
    return ::valid_leave(me,dir);
}