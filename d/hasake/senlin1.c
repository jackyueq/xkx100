// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","��Ҷ��");
       set("long", @LONG
���Ǽ�����ɽ���µ�һƬ��Ҷ�֣��������޳�Ⱥ�������̸��ź��һ
�����롣������һ�����ʵ�ɽ��������ɽ�ˣ�ɽ�������ѩ��ɽ��ȴ����
�����������߱��Ǵ��ԭ�������ڵĹ����������������������������
�ţ���Ȼ��ʧ�˵�·��
LONG);
        set("exits", ([
             "eastup"  : __DIR__"shanqiu",
             "west"  : "/d/xingxiu/shanjiao",
             "south" : __DIR__"senlin"+(1+random(4)),
             "north" : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("outdoors", "hasake");
        setup();            
}
