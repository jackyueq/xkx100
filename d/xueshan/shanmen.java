//      shanmen.c ѩɽ��ɽ��
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","ѩɽ��ɽ��");
        set("long",@LONG
�������������ѩɽ�¡�������ɽ�������Եø���׳�ۡ���Բ��
�����ڵ���Ͷ����˳��ݡ�
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "north" : __DIR__"guangchang",
                "southdown" : __DIR__"shanlu2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

