// fu-houyuan.c ��Ժ
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ���ߵ��������ζ����Ũ���ˡ�����ϸһ����
���ϱ���һ��Բ���ţ��ƺ������Ǵ����ﴫ�����ġ�����������
���ߣ����Ǻ�Ա��������ˡ�
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "southeast" : __DIR__"houhuayuan",
                "north" : __DIR__"fu-datang",
                "south" : __DIR__"fu-woshi",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3130);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}