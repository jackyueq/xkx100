// caoyuan.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ��Ե");
        set("long", @LONG
�����Ǵ��ԭ��ɳĮ����֮�أ������ϡ���ܣ��������������ȥ��
�����м�������̤������ӡ�����������ﳣ�����̶����������Ϸ�������
Щ���̡�
LONG);
        set("exits", ([
            "east" : __DIR__"caoyuana",
            "southwest" : __DIR__"caoyuan1",
            "northwest" : __DIR__"caoyuan2",
            "north" : __DIR__"caoyuan3",
 //           "north" : __DIR__"caoyuana",
            "south" : __DIR__"caoyuana",
        ]));
        set("objects", ([
                    __DIR__"npc/biaoshi" : 1,
        ])); 
        set("outdoors", "hasake");
        setup();
}
/*
int valid_leave(object me, string dir)
{
       if (dir == "north") me->add_temp("mark/steps",1);
       if (dir == "south") me->add_temp("mark/steps",-1); 
        
       if (me->query_temp("mark/steps") == 4){
            me->move(__DIR__"hswz");
            me->delete_temp("mark/steps");
            return notify_fail("��������\n");
           }  
     if (me->query_temp("mark/steps") == -4){  
           me->move(__DIR__"caoyuan1");
           me->delete_temp("mark/steps");
             return notify_fail("��������\n");
        }  
        return ::valid_leave(me, dir);
}
*/