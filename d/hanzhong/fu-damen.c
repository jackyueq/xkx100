// fu-damen ���Ҵ���
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���Ҵ���");
        set("long", @LONG
�����Ǻ��������׸�--��Ա��ҵĴ��ţ����Ϲ���һ�����ң�
����д�š�����������֡���������һ������Ӱ�ڣ�ģģ����
��������һЩʫ��֮��Ķ�����������ü���۵ļҶ���ͦ��͹�ǵ�
վ���ſ�ҫ����������������һ��Ϊ�����ʵ������Ӱԡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"dongjie",
                "south" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 3,
        ]));

	set("coor/x", -3130);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}