// sroom.c ˯��
inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
���ǹ��������˾�ס����������������Ƥ�̵أ�����Ҳ���˺�Щ��
ƤţƤ�������һ���øɲݵ�׵���ë���������һС���衣����������
�ƺ����ڼң���������˾�ЪϢ(sleep)һ�°ɡ�
LONG);
        set("sleep_room", "1");
        set("no_fight", "1");
        set("exits", ([            
            "southeast" : __DIR__"shop",            
        ]));                
        setup();
        replace_program(ROOM);
}
