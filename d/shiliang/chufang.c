// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������¼ҵĳ������¼�����Ǻ��������Ĵ�ʦ������
����ȫ�ҵĻ�ʳ���¼ҵ�ʦ����ȫ�㽭���Ǻ��������ģ���
ʱ��û������ʱ�䣬��ʦ���������������̡�
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoulang3",                
        ]));
        set("objects", ([
                __DIR__"npc/dashifu" : 1,
        ]));
      
	set("coor/x", 1590);
	set("coor/y", -1920);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 