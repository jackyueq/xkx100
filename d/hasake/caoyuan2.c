// caoyuan1.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ���
�����ߣ�������ƥ�����������ǵĺ����⡣���ߺ����߶��кö�������
�����Կ���ɳĮ�ı�Ե��
LONG);
        set("exits", ([
            "southeast" : __DIR__"caoyuan",
            "west" : __DIR__"pmchang",
            "south" : __DIR__"caoyuan1",
            "northeast" : __DIR__"caoyuan3",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}
