//      neidian.c �ڵ�

inherit ROOM;

void create()
{
        set("short","�ڵ�");
        set("long",@LONG
������ѩɽ�µ��ڵҲ�������˼��͵ĵط���ѩɽ�µ������ˡ�
������������ެ��ʦ�Ħ��������һ����ɮ��Ҳ������������������
ʦ����פ�����º�ѩɽ�·�����Զ����
LONG );
        set("exits",([
                "east" : __DIR__"tiantai",
                "west" : __DIR__"midao",
                "south" : __DIR__"zoulang3",
                "north" : __DIR__"houdian",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/jiumozhi" :1
        ]));
	set("coor/x", -70000);
	set("coor/y", -19880);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
