// room-su1.c 

inherit ROOM;
string look_sign(object me);

void create()
{
        set("short", "��³�˵ļ�");
        set("long", @LONG
������³�˵�����ʮ��ǰ��ǿ��������ֻʣ����³�˺�������������
�ˣ������������߰���ġ�����³�˲������⣬��Ϊ���������������Ĳ�
ԭ�����ǲ���ȥ��Ů������������ġ����һ�ԵĴ��̺�Ϲ��������ž�
�µ���ë̺��(tanzi)��
LONG
        );
        set("exits", ([
            "northeast" : __DIR__"shuijing",
            "east" : __DIR__"caoyuan7",
            "west" : __DIR__"caoyuan7",
            "south" : __DIR__"caoyuan7",
        ]));

        
set("item_desc", ([
		"tanzi": (: look_sign :),
	]) );
        set("objects", ([
                    __DIR__"npc/su" : 1,

        ]));

        setup();
//        replace_program(ROOM);
}
string look_sign(object me)
{
	if(me->query_skill("blade",1)<30 ) {
    return "  һ��ë̺��֯��һ���󺺣����賤�������ں�һͷ���Ӳ��������ϻ���ֻ
�������˵ı��ӣ�Զ��һͷ������Ю��β�����ߡ���һ��ë̺��֯��һ���к���
������һͷ����ǡ��Ƕ���һ��һС�������������ݣ�Ӣ���ˬ��\n";
	} else {
	me->set_temp("su_tanzi",1);
	return "  һ��ë̺��֯��һ���󺺣����賤�������ں�һͷ���Ӳ��������ϻ���ֻ
�������˵ı��ӣ�Զ��һͷ������Ю��β�����ߡ���һ��ë̺��֯��һ����
����������һͷ����ǡ��Ƕ���һ��һС�������������ݣ�Ӣ���ˬ���㶨
�˶�����Լ�о������ƺ������ż�Ϊ�����ĵ���\n";
}
}

void init()
{
        add_action("do_wudao", "liandao");  
}

int do_wudao(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

    if (!me->query_temp("su_tanzi", 1)) return 0;

    if( !arg || arg!="tanzi" ) {
                write("��Ҫ����ʲô������\n");
                return 1;
        }
        if (!weapon || weapon->query("skill_type") != "blade" )
		return notify_fail("�������޵�����ô����\n");

        if ((int)me->query_skill("blade", 1) >100 )
        return notify_fail("���Ѿ��߾�ȫ��ȥ���̺���ϰ��صĵ�����Ҫ�������޷���������Ļ��������ˣ�\n");
    
	//    me->receive_damage("jingli", 10+random(15));
		me->receive_damage("jing",random(10));
        write("�������̺���ϰ��صĵ������壬���賤���������������һЩ�йػ��������ľ�Ҫ֮���ڡ�\n");
         me->improve_skill("blade", me->query("int"));       
         return 1;
}                                     
int valid_leave(object me, string dir)
{
	me->set_temp("su_tanzi", 0);
       return 1;
	 
}
