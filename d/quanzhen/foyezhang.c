// foyezhang.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��ү��");
        set("long", @LONG
ֻ���˴���Ϊ��������һ����Ժ����ַ���������ɴ�ػ��ƣ���
Ժ�Ķ�ԫ�����ϡ�ɼ����ƺ�����һ����С����Ժ��������һƬƽԭ��
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "east"  : __DIR__"shenheyuan",
        ]));

	set("coor/x", -3180);
	set("coor/y", 70);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}