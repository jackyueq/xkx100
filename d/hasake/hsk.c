// hsk.c ����������
inherit ROOM;
void create()
{
        set("short", "����������");
        set("long", @LONG
���ǹ��������˾�ס�����񣬷�Բ�����ɣ�������һ��ľ����������
����Сľ׮Χ��һȦ����������ţƤ�����ľ׮�ٶ��ڵ��ϡ���ԭ�Ͼ�ס
�����嶼ϲ���������񣬷���򵥡����ɹ���������࣬������ͳ������
����Ϊ���ɹŰ�����
LONG);
        set("exits", ([
            "west" : __DIR__"majiu",
            "northeast" : __DIR__"caoyuan",
   //         "north" : __DIR__"caoyuan1",
            "southwest" : __DIR__"room-che",
         ]));
         set("objects", ([
                    __DIR__"npc/hasake1" : 1,
                    __DIR__"obj/cheese" : 1,
        ]));        
        setup();
        replace_program(ROOM);
}
