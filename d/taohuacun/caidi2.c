// /d/taohuacun/caidi2.c
// Last Modifiedy by Zeratul June 2000

#include <ansi.h>;
inherit  ROOM;

void harvest( object me, int times );

string  name = "", guarder = "", sort;

void  create()
{
	set("short","�˵�");
	set("long", @LONG
��������·�ߵ�һ��˵أ������Ӳݴ����������Ѿ��ķϺܾ��ˡ�
�ر��и����ز˵ص��˵������С���ӡ�
LONG
);
	set("exits", ([
		"west" : __DIR__"road1",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -80);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_seed", "zhong");
	add_action("do_seed", "seed" );
	add_action("do_guard", "observe");
	add_action("do_guard", "shou");
}

int do_seed(string arg)
{

	object  ob, me = this_player();

	if ( name != "" && name != me->query( "id" ) )  return notify_fail( "���˵��Ѿ��������ˡ�\n" );
	if ( name == me->query( "id" ) )  return notify_fail( "���Ѿ����ֲ��ˡ�\n" );
	if ( !arg || ( arg != "baicai seed" && arg != "qingcai seed" ) )  
		return notify_fail( "��Ҫ��ʲô��\n" );
	if ( !objectp( ob = present( arg, me ) ) )
		return notify_fail( "��û�����ֲ��֡�\n" );
	if ( environment(me)->query("short") != "�˵�" )
		return notify_fail( "ֻ���ڲ˵ز����ֲˡ�\n" );
	if ( me->is_busy() )
		return notify_fail( "������û���ֲˡ�\n" );
	if ( me->query("qi") < 30 )
		return notify_fail( "��̫���ˣ�Ъһ������ְɡ�\n" );
	me->add( "qi", -30 );
	message_vision( "$N�����ͷ�Ѳ˵��ϵ��Ӳݶ������ˣ�Ȼ���ֱ��ŵذ�" + ob->query("name") + "���¡�\n", me );		
	sort = explode( arg, " " )[0];
	destruct( ob );
	name = me->query( "id" );
	call_out( "harvest", 5, me, 5 );
	
	return 1;
}

void harvest( object me, int times )
{
	int i;
	object ob;
	string *msg=({
HIW "\n����������ˣ����Ʈ��һƬƬ���ƣ������ڲ˵��Ͽա�\n����Ҫ�����ˣ��Ͻ����������һ�ڰɡ�\n" NOR,
HIC "\n����΢¶��һȺ������ʳ��������������ط��������ڲ˵��\n������Ǹ��߰ɡ�\n" NOR,		
HIY "\n�м�����������ŷ��Ƶ�Ҷ�ӣ�����ò��ˣ���׽һ׽���ˡ�\n" NOR,
HIG "\n�����͵Ĳ�����΢���������ͷ��\n�������һ���Ǹ�����գ��㲻��ϲ��ü�ҡ�\n" NOR,
	});
	
	if ( times-- > 0 ) {
		i = random(4);
		write( msg[i] );
		if ( i < 3 )
			call_out( "gain", 5, me, i, times );
		else   	call_out( "harvest", 10, me, times );
	}
	else {
		ob = new( __DIR__"npc/obj/" + sort );
		ob->move( me );
		message_vision( HIG "\n$N�ջ���һ��" + ob->query("name") + "��\n" NOR, me );		
		name = "";
		guarder = "";
	}
}

void gain( object me, int i, int times )
{
	string *fail_msg=({
WHT "�㻹û��������ӵĲ��ϣ������������������£����綼����ˮ���ˡ�\n" NOR,		
CYN "�㶫�����ܵظ��񣬿�����߸����˼�ֻ���Ǳ�������һȺ����һ�������ͱ��Ĺ��ˡ�\n" NOR,
YEL "��һʱ�벻���Ը����ӵİ취��ֻ�����������Ų��类һ��һ��Ե���\n" NOR,
	});
	string *suc_msg=({
HIW "���ֽ��������ҵ����Ӻ�ľͷ�����������������ӣ��ٴ����Ҳ�����ˡ�\n" NOR,
HIC "�����˼��������˲��ڲ˵������ŵö������ˡ�\n" NOR,
HIY "�����һЩҩ������������������Ӷ���Ѭ���ˡ�\n" NOR,		
	});

	if ( !stringp(guarder) || guarder != me->query("id") || random( me->query("kar") ) < 5 ) {
		write( fail_msg[i] );
		message_vision( WHT "\n���綼�����ˣ�$N������׷��ˡ�\n" NOR, me );
		name = "";
		guarder = "";		
	} 
	else {
		write( suc_msg[i] );
		call_out( "harvest", 3, me, times );
	}
		
}

int do_guard()
{
	object me = this_player();
	
	if ( me->query("id") != name )
		return notify_fail( "�㲻������˵ص����ˣ������ز˵ء�\n" );
	if ( me->query("id") == guarder )
		return notify_fail( "���Ѿ����ز˵��ˡ�\n" );
	write( "�㿪ʼ�ز˵ء�\n" );
	guarder = name;
	return 1;
}
	
int valid_leave( object me, string dir )
{
	if ( guarder == me->query( "id" ) )
		return notify_fail( "�������ز˵أ������뿪��\n" );
	return 1;
}

void reset()
{
	if ( !present( name, this_object() ) )
		name = "";
	::reset();		
}	
