// fu-mishi.c ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�����ң�����ɢ���ż�����Ѫ�ı��ӣ�����һЩ��
�ָ������̾ߡ�������˵��Ȼ���飬���Ա������Ǹ���������
�Ķ�ԡ�
LONG
        );
        set("exits", ([
                "northwest" : __DIR__"fu-midao",
                "up" : __DIR__"fu-woshi",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/xuejie" : 1,
        ]));
	set("coor/x", -3130);
	set("coor/y", -60);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}