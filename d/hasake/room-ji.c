// room-ji.c ����

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ڲ��嶫�����������һ�������������ǽ�ݶ�����ʽ������
�غ��˵�ש�ݣ�ֻ����Ϊ��ª���Ա���һ��Сˮ������ĵ�����С����
�棬����̽ͷ�Ӵ�����������������֪������һ����ͬʱ̽������������
ȥ���Ǵ����ˡ�
LONG
        );
        set("exits", ([
            "enter" : __DIR__"room-ji1",
            "south" : __DIR__"road2",
           "northwest" : __DIR__"gebi1",
            "southeast" : __DIR__"caoyuan6",
        ]));

        set("outdoors", "hasake");

        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       if( dir == "northwest" && !userp(me))
            return notify_fail("...\n");  
      
       return ::valid_leave(me,dir);
}
