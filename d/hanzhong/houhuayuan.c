// houhuayuan.c ��԰
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
������һ��С��԰�����ҵ����Ÿ��ֻ��ݣ��������˴���
�Ӳ��Ѿ����úܸ��ˡ���һЩ��ģ��׵��ʻ������ڲݴ��У���
���㲻�ϵ�Ʈ����������һ��С�ţ�������һ������С¥��
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "northwest" : __DIR__"fu-houyuan",
                "south"     : __DIR__"guanjinglou",
                "east"      : __DIR__"houhuayuan1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3120);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
