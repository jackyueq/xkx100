// caoyuan3.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣���߿��Կ���������������
��ȥ����ɳĮ�ˡ�
LONG);
        set("exits", ([
            "southwest" : __DIR__"caoyuan2",
            "northwest" : __DIR__"shop",
            "northup" : __DIR__"road1",
            "southdown" : __DIR__"caoyuan",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
